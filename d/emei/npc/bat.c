//bat.c ����

inherit NPC;

void create()
{
        set_name("����", ({"bianfu","bat"}) );
	set("race", "����");
        set("age", 8);
        set("long", "����һֻ�����������ڶ�����\n");

        set("str", 40);
        set("dex", 50);

        set_temp("apply/attack", 33);
        set_temp("apply/armor", 20);

        set("chat_chance", 2);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
        "�������˵طɹ���������ͷ��ת��һȦ���ַ����ˡ�\n",
         }) );

        setup();
}
