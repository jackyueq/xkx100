// Feb. 6, 1999 by Winder
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}
void create()
{
        set_name("���߽���", ({ "jinshe jianpu", "jianpu"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����Ǽ����Ž����ɾ�һ����Ѫ�Ľ��߽��ס�\n");
                set("value", 50000);
                set("material", "paper");
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set("no_put", "�Ȿ���ײ��ܷŽ�ȥ��\n");
        }
}
int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int jslevel; 
        int neili_lost;
        if (!(arg=="jinshe jianpu" || arg == "jianpu" ))
        return 0;
        if (where->query("pigging")){
                write("�㻹��ר�Ĺ���ɣ�\n");
                return 1;
        }
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }
        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }
/*        if(!arg || !objectp(ob = present(arg, me)) ){
                write("��Ҫ��ʲô��\n");
                return 1;
        }
*/
        if (!id(arg)) { 
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }
        switch(random(3)) {
          case 0:
        message("vision", me->name() + "ר�ĵ��ж����߽��ס�\n", environment(me), me);
              break;
          case 1:
        message("vision", me->name() + "���Ž��߽��ף����к����������⡣\n", environment(me), me);
              break;
          case 2:
        message("vision", me->name() + "ͻȻ���½��ף�վ�������Ȼ��˼��¡�\n", environment(me), me);
              break;
        }
        if( (int)me->query("jing") < 15 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
        if ( me->query_skill("jinshe-jian", 1) > 84) neili_lost = 55;
        else
        if ( me->query_skill("jinshe-jian", 1) > 74) neili_lost = 40;
        else neili_lost = 5;
        if( (int)me->query("neili") < neili_lost) {
                write("�������������޷�������ô������书��\n");
                return 1;
        }
        jslevel = me->query_skill("jinshe-jian", 1);
        if( (int)me->query("combat_exp") < (int)jslevel*jslevel*jslevel/10 ) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        } 
        if( me->query_skill("jinshe-jian", 1) > 200){
                write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                return 1;
        }
        me->receive_damage("jing", 45);
        me->set("neili",(int)me->query("neili")-neili_lost);
        me->improve_skill("jinshe-jian", (int)me->query_skill("literate", 1)/3+1);
        write("���ж������߽��ס����ؾ������з��������⣬�����ĵá�\n");
        return 1;
}
