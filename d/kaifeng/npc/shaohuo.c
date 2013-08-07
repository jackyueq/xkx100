inherit NPC;

void create()
{
	set_name("�ջ�ɮ��", ({"shaohuo seng", "seng", "shaohuo"}));
        set("long", "רְ�������ջ��ɮ�ˡ�\n" );
        set("gender", "����");
        set("attitude", "peace");

        set("age", 23);
        set("str", 15);
        set("int", 16);
        set("con", 20);
        set("max_qi", 300);
        set("combat_exp", 2000);

        set_skill("force", 10);
        set_skill("unarmed",10);
        set_skill("blade", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10);
        set_skill("literate",10);
        set_skill("staff",10);

        setup();
        carry_object(__DIR__"obj/xuan-cloth")->wear();
	carry_object(__DIR__"obj/chuihuo")->wield();
        add_money("coin", 50);
}
