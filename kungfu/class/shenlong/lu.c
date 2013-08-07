// lu.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);
int ask_me();
string ask_huang();

void create()
{
	set_name("½����", ({ "lu gaoxuan", "lu" ,"gaoxuan"}));
	set("nickname",HIC "�������" NOR);
	set("long","����ʮ������ͣ���ʿ��磬��ͥ������������Բ����ò��ΪӢ��������Ͱ����ס�Ȼ��������ݣ�ǡ����̼����ɱ��֮��һ�㡣\n" );
	set("gender", "����");
	set("age", 37);
	set("str", 35);
	set("dex", 20);
	set("max_qi",1500);
	set("qi",1500);
	set("max_jing",500);
	set("jing",500);
	set("combat_exp", 300000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 70);
	set_skill("dulong-dafa", 70);
	set_skill("dodge", 70);
	set_skill("yixingbu", 70);
	set_skill("hand", 70);
	set_skill("shenlong-bashi", 100);
	set_skill("parry", 70);
	set_skill("hook", 70);
	set_skill("ruyi-hook", 100);
	set_skill("literate", 70);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("parry", "shenlong-bashi");
	map_skill("hook", "ruyi-hook");
	prepare_skill("hand", "shenlong-bashi");
	set("env/wimpy", 60);
	set("party/party_name", HIY"������"NOR);
	set("party/rank", "��ʦ");
	set("party/level", 2);
	create_family("������", 2, "����");

	set_temp("apply/damage", 60);
	set("book_count", 1);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
	set("inquiry", ([
		"�鰲ͨ" : "������������˵����",
		"�����" : "������ɸ������������룬�������Ŀ��磬�����ķ���",
		"����"   : "û��û�صġ�",
		"������" : "�����������ݵĶ������򣬴������ڳ����㵽��",
		"������" : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"���"   : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"����"   : "����Ƣ�����ã�Ҫ�������Ĳźá�\n",
		"�ں�"   : "���겻�ϣ������ɸ����������룡������ʥ��\n",
		"�ؼ�"   : (: ask_me :),
		"book"   : (: ask_me :),
		"�ۻ�"   : (: ask_huang :),
		"huang"  : (: ask_huang :),
	]) );
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(__DIR__"obj/shenlongci")->wield();
	add_money("silver", 10);
}

void init()
{
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIY "������" NOR ) {
		command("say �㲻�Ǳ��̽��ڣ�������������");
		return;
	}
	if ((int)ob->query_skill("literate",1) < 40 ) {
		command("say ���ѧ��̫���ˣ�����ŬŬ�������һ�°ɣ�");
		return;
	}
	if ((int)ob->query("shen") > -0 ) {
		command( "say �������������������������������ְ׵�����򽻵�������ذɣ�");
		return;
	}
	command("say �ܺã��ܺá�");
	command("recruit " + ob->query("id"));
}
string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����̵��ؼ����ڴ˴���";
	add("book_count", -1);
	if (random(2) == 0) ob = new("/clone/book/shoufa");
	else ob = new("/clone/book/bufa");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ�"+ob->query("name")+"����\n");
	return "�ðɣ��Ȿ��"+ob->query("name")+"�����û�ȥ�ú����С�";
}
string ask_huang()
{
	mapping fam; 
	object ob, me = this_player();

	if (!(fam = me->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";
	if( present("xionghuang", me) )
		return RANK_D->query_respect(me)+"���������ϲ����ۻ�����ô����Ҫ�ˣ�����̰�����У�";
	if( time() < me->query("huang/time") + 1800 )
		return RANK_D->query_respect(me) + "�㲻�Ǹ�Ҫ���ۻƣ���ô����Ҫ�ˣ�����ʱ�������ɡ�";

	me->set("huang/time", time()); 
	ob = new(VEGETABLE_DIR"xionghuang");
	ob->move(me);
	return "�ðɣ����ۻ������ȥ�ɡ�";
}
#include "/kungfu/class/shenlong/shenlong.h"; 
