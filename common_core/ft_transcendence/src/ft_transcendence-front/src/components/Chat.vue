/* eslint-disable */
<template>
  <div id="chat">
    <div id="header-chat">Chat</div>
    <div id="list-chat">
      <div id="add-button" @click="createNewCanal()">
        <img class="icon" src="../assets/add.svg" />
      </div>
      <div v-for="chat in chats" :key="chat" class="chat-canal">
        <img
          id="chat-canal-visibility"
          v-if="chat.visibility == 0"
          src="../assets/earth-globe.svg"
        />
        <img
          id="chat-canal-visibility"
          v-else-if="chat.visibility == 1"
          src="../assets/lock.svg"
        />
        <img
          id="chat-canal-visibility"
          v-else-if="chat.visibility == 2"
          src="../assets/chat.svg"
        />
        <a class="chat-canal-link" @click="updateShowedCanal(chat.id)">
          {{ chat.name }}
        </a>
        <img
          id="chat-canal-settings"
          v-if="isadmin && chat.id == canalid"
          @click="updateUsers()"
          src="../assets/user.svg"
        />
        <img
          id="chat-canal-settings"
          v-if="isadmin && chat.id == canalid"
          @click="updateCanal()"
          src="../assets/settings.svg"
        />
        <img
          id="chat-canal-settings"
          v-if="isadmin && chat.id == canalid"
          @click="deleteCanal()"
          src="../assets/cancel.svg"
        />
      </div>
    </div>
    <div
      id="messages-box-chat"
      v-if="this.getVisibility() == 1 && !this.logged"
    >
      <input
        ref="password"
        type="password"
        class="login-field"
        name="password"
        @keyup.enter="login()"
      />
      <button class="login-submit" @click="login()">login</button>
    </div>
    <div id="messages-box-chat" v-else>
      <div
        v-for="message in messages"
        :key="message"
        :class="
          message.author == this.userid ? 'message-current-user' : 'message'
        "
      >
        <div
          v-if="this.userid != message.author"
          v-on:click="goToUserProfile(getUserImage(message.author))"
        >
          <img
            class="user-image"
            v-bind:src="getUserImage(message.author)"
          />
          <div class="content" :key="message">
            {{ message.message }}
          </div>
        </div>
        <div v-else>
          <div class="content" :key="message">
            {{ message.message }}
          </div>
        </div>
      </div>
    </div>
    <form
      v-if="this.canalid != -1"
      ref="formChat"
      @submit.prevent="messageSubmit"
      id="input-chat"
      autocomplete="off"
    >
      <input
        type="text"
        id="input-text-chat"
        v-model="inputMessage"
        placeholder="Write a message..."
      />
      <input type="submit" id="input-submit-chat" value="Send" />
    </form>
    <h3 v-else>SELECT A CANAL FIRST</h3>
  </div>
</template>

<script>
export default {
  data() {
    return {
      messages: [],
      chats: [],
      avatarURL: "",
      canalid: -1,
      inputMessage: "",
      userid: -1,
      userImage: "",
      canalname: "",
      logged: false,
      isadmin: false,
    };
  },
  async mounted() {
    this.avatarURL = this.$store.state.user.avatarURL;
    this.userid = this.$store.state.user.id;

    var objDiv = document.getElementById("messages-box-chat");
    if (objDiv != null) objDiv.scrollTop = objDiv.scrollHeight;
    this.activate();
  },
  methods: {
    async activate() {
      this.refreshChat();
    },
    // Submit messages data to database
    messageSubmit:  async function () {
      if (this.inputMessage == null || this.inputMessage == "") return;
      if(this.getVisibility() == 1 && !this.logged)
        return;
      // Check if sender is muted
      const self = this;
      if (self.$store != undefined && self.$store != null) {
        await self.$store
          .dispatch("getUser", self.$store.state.user.id)
          .then(function (result) {
            if (result.mute == null || result.mute == undefined) return;
            const mutes = result.mute.split("|");
            if (mutes != "") {
              for (const x in mutes) {
                if (mutes[x] == "" || mutes[x] == undefined) break;
                let canalId = +mutes[x].split(";")[0];
                let timestamp = +mutes[x].split(";")[1];
                if (canalId == self.canalid && timestamp > new Date().getTime())
                {
                  self.inputMessage = "";
                  return;
                }
                 
              }
            }
          });
      if (self.inputMessage == "")
        return ;
      if (this.$store != undefined && this.$store != null && self.inputMessage != "") {
        let msg = {
          id: null,
          author: this.$store.state.user.id,
          message: this.inputMessage,
          canalid: this.canalid,
        };
        await this.$store.dispatch("createMessage", msg);
      }
      this.inputMessage = "";
      }
     
    },
    refreshChat: function () {
      const self = this;

      this.userid = this.$store.state.user.id;
      setInterval(async function () {
        if (self.$store != undefined && self.$store != null) {
          self.isAdmin();
          var specs = {
            canalid: self.canalid,
            user: null,
          };
         await self.$store
            .dispatch("getUser", self.$store.state.user.id)
            .then(async function (result) {
              specs.user = result;
              if (result == undefined)
                return ;
              if (result.canals != "" && result.canals != undefined) {
                let list = result.canals.split(":");
                let chats = [];
                for (let x in list) {

                 await  self.$store
                    .dispatch("getCanalById", list[x])
                    .then(function (result) {
                      chats.push(result[0]);
                      self.$store
                        .dispatch("getMessagesByCanalId", specs)
                        .then(function (result) {
                          self.messages = result;
                        });
                    });
                }
                if (chats != self.chats) 
					self.chats = chats;
              }
			  else
			  	self.chats = []
            });
        }
      }, 1000);
    },
    createNewCanal: function () {
      this.$root.admin = 1;
      this.$root.admin_method = "create";
    },
    updateCanal: function () {
      this.$root.admin = 1;
      this.$root.admin_method = "update";
      this.$root.admin_id = this.canalid;
    },
    deleteCanal: function () {
      let self = this;
      if (confirm("Are you sure you want to delete this canal?")) {
        self.$store
          .dispatch("deleteCanal", this.canalid)
          .then(function (result) {
            self.canalname = "";
            self.canalid = -1;
            self.refreshChat();
          });
      }
    },
    updateShowedCanal: function (canalid) {
      this.canalid = canalid;
      const self = this;
      self.$store
        .dispatch("getLogState", {
          canalid: canalid,
          value: self.$store.state.user.id,
        })
        .then(function (result) {
          self.logged = result;
          //console.log("wtf",result);
        });
    },
    updateUsers: function () {
      this.$root.admin = 2;
      this.$root.admin_method = "update";
      this.$root.admin_id = this.canalid;
    },
    getUserImage: function (id) {
      const self = this;

      if (
        self.$store != undefined &&
        self.$store != null &&
        id != null &&
        id != undefined
      ) {
        self.$store.dispatch("getUser", id).then(function (result) {
          self.userImage = result.avatar;
        });
        return self.userImage;
      }
      self.userImage = "thallard";
      return self.userImage;
    },
    goToUserProfile: function (user) {
      if (user != undefined && user != null) this.$router.push(`/user/${user}`);
    },
    getCanalName: function () {
      const self = this;
      if (self.$store != undefined && self.$store != null)
        self.$store
          .dispatch("getCanalById", self.$store.state.canalid)
          .then(function (result) {
            self.canalname = result.name;
          });
    },
    login: function () {
      const self = this;
      //console.log(this.$refs.password.value);
      if (
        this.$refs.password.value != undefined &&
        this.$refs.password.value != null
      ) {
        self.$store
          .dispatch("loginCanal", {
            canal_id: this.canalid,
            user: self.$store.state.user.id,
            password: self.$refs.password.value,
          })
          .then(function (result) {
            if (result.error == null || result.error == undefined) {
              self.logged = true;
              self.refreshChat();
            }
          });
      }
    },
    getVisibility: function () {
      const self = this;
      let ret = -1;
      this.chats.forEach(function (item) {
        if (item.id == self.canalid) {
          ret = item.visibility;
        }
      });
     // console.log("return value:", ret, self.logged);
      return ret;
    },
    isAdmin: function () {
      let self = this;
      this.$store
        .dispatch("isCanalAdmin", {
          user_id: this.$store.state.user.id,
          canal_id: this.canalid,
        })
        .then(function (result) {
          self.isadmin = result;
        });
    },
  },
};
</script>

<style>
@import "./../assets/styles/chat.css";
</style>
