<template>
    <b-card style="max-width: 20rem;" class="mb-2">
        <p>id: {{id}}</p>
        <p>value: {{value}}</p>
        <p>active: {{active}}</p>
        <b-button :variant="variant" v-on:click="toggleSensor">{{label}}</b-button>
    </b-card>
</template>

<script>
    export default {
        name: 'SettingsSensor',
        props: ['id','title', 'value', 'active'],
        computed: {
            variant: function () {
                return this.active?'danger':'primary';
            },
            label: function () {
                return this.active?'Remove sensor':'Add sensor';
            }
        },
        methods: {
            toggleSensor: function () {
                this.$store.commit('toggleSensor', this.id);
            }
        }
    }
</script>
