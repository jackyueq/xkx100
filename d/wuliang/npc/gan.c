// Npc: /gan.c
// Date: Oct.18 1999 by Winder

inherit NPC;
string ask_me();
void create()
{
	set_name("�ɹ��", ({ "gan guanghao", "gan", "guanghao"}));
	set("gender", "����");
	set("attitude", "friendly");

	set("age", 20);
	set("shen_type", -1);
	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 550);
	set("max_neili", 550);
	set("jiali", 40);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("changquan", 40);
	set_skill("parry", 40);
	set_skill("damo-jian", 40);
	set_skill("sword", 40);

	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
	set("inquiry", ([
		"�����"    : (: ask_me :),
		"����Ů"    : (: ask_me :),
		"�������"  : (: ask_me :),
		"����"      : (: ask_me :),
		"�������"  : "���Ǳ��ɽ��أ��κ����˲������롣�ɷ����ɣ��ɽ���������֮�ء�",
	]));

	create_family("����������", 5, "����");
	setup();

        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

string ask_me()
{
	this_player()->set_temp("marks/wuliang", 1);
	return "��Ȼ����ײ�������ǵĺ��£�Ҳ�������Ƕ��֣��Լ��������˶ϰɡ�";
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        tell_object(ob,
"\n�ɹ���������������ң��������պ��ģ��͵�����ˮ���������ˡ���
�������Ц�������������������ˣ��ɲ������Ҳ�����𣿡�\n");
}

