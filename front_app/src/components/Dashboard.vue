<template>
    <b-row align-h="center" align-content="center">
        <b-col v-for="item in items" lg="6" style="min-height: 300px; min-width: 300px">
            <Gauge :id="item.id" :value="item.value"></Gauge>
        </b-col>
    </b-row>
</template>

<script>
    import Gauge from './Gauge.vue'

    export default {
        name: 'Dashboard',
        components: {
            Gauge,
        },
        computed: {
            items: function () {
                return this.$store.getters.activeSensors
            }
        }
    }
</script>
