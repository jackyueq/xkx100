// aman.c

inherit NPC;

void create()
{
        set_name("����", ({ "aman" }) );
        set("gender", "Ů��" );
        set("age", 18);
        set("long", "�������Ĺ����˹���,��������,��Ŀ毺�, �۹�����˸��Ц�⡣\n");
        set("shen", 200);
        set("combat_exp", 1000);
        set("str", 16);
        set("dex", 18);
        set("con", 12);
        set("int", 24);
        set("per", 39);
        set("attitude", "friendly");
        set("inquiry", ([
            "����" : "�������������㡣\n",            
            "������" : "�����Ұ���������³�˴���һ���ǲ�ԭ�ϵ�Ӣ���أ�\n",
        ]) );
        setup();
        add_money("silver", 5);
        carry_object(__DIR__"obj/qun")->wear();
}
