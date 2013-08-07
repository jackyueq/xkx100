// azi.c ����

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_azi();

void create()
{
//	set_name("����", ({ "azi" }));
	set_name("����", ({ "a zi","azi" }));
	set("nickname", "������Сʦ��");
	set("long", 
		"һ�������µ���ò��Ů�������Ӱ׾���������������
������������͸��һ��а����\n");
	set("gender", "Ů��");
	set("age", 15);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", -1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 24);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 10);
	set("combat_exp", 50000);
	set("score", 10000);

	set_skill("force", 40);
	set_skill("huagong-dafa", 50);
	set_skill("dodge", 30);
	set_skill("zhaixinggong", 40);
	set_skill("strike", 30);
	set_skill("chousui-zhang", 40);
	set_skill("claw", 30);
	set_skill("sanyin-wugongzhao", 40);
	set_skill("parry", 20);
	set_skill("poison", 20);
	set_skill("staff", 20);
	set_skill("tianshan-zhang", 80);
//	set_skill("literate", 30);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("env/wimpy", 60);

	set("inquiry", ([
		"������" : "������룬�Ͱ���Ϊʦ��",
		"�"   : "�ٺ٣�������ô���׾͸����㡣",
		"���޺�" : "ȥ���޺���ʲô������Ϊʦ�͹���ѧ���ˡ�",
		"������" : "����������е���û��ûС�ġ��Ժ�����ɣ�",
		"����"   : "��öവ�����ɣ���������г�ͷ֮�ա�\n",
		"����ľ��" : "�����˸��ҽ�������б������Լ�ȥ�á�",
		"���"   : "���ҽ�����嶼��֪���������Ǹ�����ϡ�",
		"����"   : "���ʵĿ��������ɣ�",
		"����"   : "Ů�����׶��ˣ�����������ϲ�����еĵø��ӰѾ���",
		"����"   : "���Ǳ������Ұ�����Ҫ��ô������\n",
		"��ľ����" : (: ask_azi :),
	]));
	create_family("������", 2, "����");
	setup();
	carry_object("/clone/medicine/nostrum/qingxinsan");
	carry_object("/d/xingxiu/obj/baihuqiu")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("shen") > 0)
	{
		command("say �㿴��ȥ���Ǹ����������ҲŲ��������ء�");
		return;
	}
	command("say �������Ҿ��������˰ɡ�");
	command("recruit " + ob->query("id"));
}
string ask_azi()
{
	mapping fam; 
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if( this_player()->query_temp("smwd/step") )
	{
		this_player()->delete_temp("smwd/step", 1);
		ob=new(__DIR__"obj/ding");
		ob->move(this_object());
		command("fear");
		command("mapi "+this_player()->query("id"));
		return "ʦ�������˼ҵı���������ô�������⣿����λС"+RANK_D->query_close(this_player())+"һ������˰ɣ�";
	}
	else return "ʦ�������˼ҵı���������ô�������⣿��";
}

