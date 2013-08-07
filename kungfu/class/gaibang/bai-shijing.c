// bai-shijing.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

string ask_quit();
void create()
{
	set_name("������", ({"bai shijing", "bai", "shijing"}));
	set("nickname", "ؤ������");
	set("gender", "����");
	set("age", 50);
	set("long", 
"ִ�����ϰ���������ɫ���ƣ�����������˽�����д�С�˵ȣ���Ȼ����Υ
�����������������Ҳ�Ǿ������֡�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	set("no_get", "1");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("inquiry", ([
		"����"    :   (: ask_quit :),
		"ִ��"    :   (: ask_quit :),
		"�˰�"    :   (: ask_quit :),
		"tuibang" :   (: ask_quit :),
	]));
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 95);            // �����ڹ�
	set_skill("huntian-qigong", 90);   // ��������
	set_skill("hand", 90);             // �����ַ�
	set_skill("suohou-hand", 85);      // ����������
	set_skill("staff", 90);            // �����ȷ�
	set_skill("fengmo-staff", 85);     // ��ħ�ȷ�
	set_skill("dodge", 90);            // ��������
	set_skill("xiaoyaoyou", 95);       // ��ң��
	set_skill("parry", 85);            // �����м�
	set_skill("staff", 90);            // ��������
	set_skill("strike",85);  // �����Ʒ�
	set_skill("lianhua-zhang",85); // ������
	set_skill("xianglong-zhang",85);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	map_skill("force", "huntian-qigong");
	map_skill("staff", "fengmo-staff");
	map_skill("parry", "fengmo-staff");
	map_skill("hand", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", RED"�Ŵ�����"NOR);
	set("party/level", 9);
	create_family("ؤ��", 10, "ִ������");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangzhang")->wield();
}

init()
{
	object ob;
	mapping myfam;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		myfam = (mapping)ob->query("family");
		if((!myfam || myfam["family_name"] != "ؤ��") && (!wizardp(ob)))
		{
			remove_call_out("saying");
			call_out("saying", 1, ob);
		}
	}
	add_action("do_decide", "decide");
}
void attempt_apprentice(object ob)
{
	command("say �Ϸ���ͽ�ܣ�"+RANK_D->query_respect(ob)+"������ذɡ�");
}
void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
string ask_quit()
{
	mapping fam;
	object ob,me=this_player();
	string *sname;
	int i;

	if (!(fam = me->query("family")) || fam["family_name"] != "ؤ��")
		return RANK_D->query_respect(me) +
		"�뱾��������������֪�˻��Ӻ�̸��";
	if(!me->query("party") || me->query("party/party_name") != HIC"ؤ��"NOR)
	{
		return "�㲻��ؤ�����ˣ����߾͸��ҹ���";
	}
	if(me->query("combat_exp") < 100000)
	{
		return "����ؤ��Ҳû�������Ӱ����������߾����ߣ���";
	}
	me->set_temp("pending/quit_gaibang", 1);
	return "�ðɣ��ѳ�ؤ�������ܱ��﷨������ȥ�㱾���书��\n��þ;���(decide)�ɡ�";
}
int do_decide()
{
	if( !this_player()->query_temp("pending/quit_gaibang") )
		return 0;

	message_vision(
"$n���纮˪������������ִ�����ӣ��뱾�﷨������\n
��������¾�����������Ӧ�������ǣ���ÿ�˴ӱ��󲼴���ȡ��һ���Ʋ���
�����򿪰�����ȡ��һ���̵����ű������Ȼ�Ķ̵�������һ��һ���ĳ�
�̴�С�������ҫ֮�£�������������ɭɭ�Ĺ�ɡ�һ��ִ����������һ��
��ľ������ͬʱ���ű��̵�������ľ�У����ֶ��룬����ŵ������쳣����
�������е����������뼯���������󡣡�\n
$nѺ��ɤ�ӣ��������������̣���
"HIR"����ִ�����ӷ����缲���������$Nֻ���þ�ʹ����ߴ󳱣���Ȼ��������
ǰһ��ѣ�Ρ�΢һ����ִ�������Ѿ��յ������ˡ�\n"NOR"
$n��Ц�ŵ�������ȥ�ɣ����±��ϲ������Խ����ؤ����û������������\n
", this_player(), this_object() );
	this_player()->delete_temp("pending/quit_gaibang");
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->add("combat_exp", -23250);
	this_player()->set("combat_exp",this_player()->query("combat_exp")*8/9);
	this_player()->delete("party");
	return 1;
}

