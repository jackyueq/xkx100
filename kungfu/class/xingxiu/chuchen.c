// shihou.c ������

inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("������", ({ "chuchen zi", "chuchen", "zi" }));
	set("nickname", "�����ɰ˵���");
	set("long", 
	"������䰫��ȴ�����ְ��������ſ�ȥ������Ϊ��ΰ������Ҳ�����ݡ�
�����յĸ����ֳ����ء�\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 30);
	set("int", 15);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 15);
	set("combat_exp", 100000);
	set("score", 20000);

	set_skill("force", 60);
	set_skill("huagong-dafa", 4);
	set_skill("dodge", 60);
	set_skill("zhaixinggong", 50);
	set_skill("claw", 50);
	set_skill("sanyin-wugongzhao", 70);
	set_skill("strike", 50);
	set_skill("chousui-zhang", 70);
	set_skill("parry", 50);
	set_skill("staff", 80);
  	set_skill("tianshan-zhang", 80);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("no_get",1);
	set("env/wimpy", 60);
	set("inquiry", ([
		"������" : "��ϧ���ɲ�׼����ͽ, ������ɰ���Ϊʦ��",
		"�"   : "�ʰ��ϰɡ�",
		"����"   : "Сʦ����������ϲ��, ��ȥ�����ɡ�",
		"����"   : "Ҫ��������, �����ס��Сʦ�á�",
		"����"   : "��öവ������, ��������г�ͷ֮�ա�\n",
		"������" : "����������е���? û��ûС�ġ��Ժ������! ",
		"���޺�" : "�����ں�æ, �ұ��˴���ȥ�ɡ�",
		"�ȷ�"   : "����ɽ�ȷ�, �������֡�", 
		"��ɽ�ȷ�" : "���������������ɡ�",
		"������" : "�Ҹ�ɽ������",
		"ɽ��"   : "����߶ʲô? �Լ�ȥ�ҡ�",
		"����ľ��" : "�ҿ�û���, �����������㡣",
		"ɽ��"   : "����, ����ʯ�ƿ����Ϳ��Խ�ȥ����? ",
		"����"   :    (: ask_me :),
	]) );
	set("zhang_count", 4);
	create_family("������", 2, "����");
	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
  	carry_object("/d/xingxiu/obj/changpao")->wear();
}

void do_killing(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	this_object()->kill_ob(ob);
}

string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";

	if ( present("gangzhang", this_player()) )
		return RANK_D->query_respect(this_player()) + "���������ϲ����и�������������Ҫ�ˣ� ����̰�����У�";

	if (query("zhang_count") < 1) return "�Բ��𣬸����Ѿ�������";
	ob = new("/clone/weapon/gangzhang");
	ob->move(this_player());
	add("zhang_count", -1);
	message_vision("$N���һ�����ȡ�\n",this_player());
	return "��ס���𶪵��ˡ�";
}

void attempt_apprentice(object ob)
{
	command("say ���ɻ�û��������ͽ�ء�");
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();

	if (interactive(ob) && !environment(ob)->query("no_fight") &&
		((fam = ob->query("family")) && fam["family_name"] != "������"))
	{
		command("say �󵨿�ͽ�����Ҵ������޺���͵��������\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}
