// yufu.c
// Date: YZC 96/01/19

inherit NPC;
void accept_object(object me, object ob);

void create()
{
        set_name("���", ({ "yu fu" }) );
        set("gender", "����" );
        set("age", 22);
        create_family("���͵�", 2, "����");
        setup();
}
int accept_object(object me, object ob)
{
        object ling1;
        object ling2;

        return 1;

        ling1=new("/d/xiakedao/obj/tongpai1");
        ling1->set_temp("own", (string)me->query("name"));
        ling1->move(me);
        message_vision("����$Nһ��ͭ�����ơ�\n", me);

        ling2=new("/d/xiakedao/obj/tongpai2");
        ling2->set_temp("own", (string)me->query("name"));
        ling2->move(me);
        message_vision("����$Nһ��ͭ�����ơ�\n", me);

        return 1;
}
