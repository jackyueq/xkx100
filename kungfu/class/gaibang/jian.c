// jian.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_quit();
void create()
{
	set_name("����", ({"jian zhanglao", "jian", "zhanglao"}));
	set("gender", "����");
	set("age", 50);
	set("long", "������ؤ���ִ�����ϣ�������ִ�Ʒ����Լ�������ȡ�\n"
		"������������𣬵�������˭���������־������顣\n");

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
		"������"  :   (: ask_me :),
		"qingzhu" :   (: ask_me :),
		"ling"    :   (: ask_me :),
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

	
	map_skill("force", "huntian-qigong");
	map_skill("staff", "fengmo-staff");
	map_skill("parry", "fengmo-staff");
	map_skill("hand", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("strike", "xianglong-zhang");
	prepare_skill("strike", "xianglong-zhang");

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", RED"�Ŵ�����"NOR);
	set("party/level", 9);
	create_family("ؤ��", 18, "ִ������");
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

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	message_vision("\n���Ͽ���$Nһ�ۣ������˵����������������˼�˵�Ҳ���"
	    "�������ؤ����ӣ�\n���ֲ�����ؤ��Ҵ����ܿ��԰ɣ���\n"
	    "˵������һ̧��$N˳��Ӧ��һ������ɵġ�ƨ�����ƽɳ����ʽ��"
	    "������ߴ\n\n", ob);
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/city/pomiao");
	message("vision","ֻ�����ء���һ����������" +  ob->query("name") +
	"��С������˳�����ƨ������һ�������Ьӡ��\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
	command("say �Ϸ���ͽ�ܣ�"+RANK_D->query_respect(ob)+"������ذɡ�");
}
string ask_me()
{
	mapping fam;
	object ob,me=this_player();
	string *sname;
	int i;

	if (!(fam = me->query("family")) || fam["family_name"] != "ؤ��")
		return RANK_D->query_respect(me) +
		"�뱾��������������֪�˻��Ӻ�̸��";

	ob = new(__DIR__"obj/qingzhu-ling");
	ob->move(me);
	message_vision("$N���һ�������\n",me);

	return "�ðɣ�ƾ���������������������ͬ�Ŵ�ʦ����ս��";

}
int accept_object(object ob, object obj)
{
	mapping fam;
	string newtitle;
	object me = this_object();
	if (!(fam = ob->query("family")) || (fam["family_name"] != "ؤ��"))
	{
		command("say ���Ǻ��ˣ����Ҵ����Ǻ����⣿");
		me->kill_ob(ob);
		return 0;
	}
	if( ob->query("combat_exp") < 2000)
	{
		command("say ��Ľ�������̫�ͣ�����û�к������ְ˾��\n");
		return 0;
	}
	if( ob->query("party") && ob->query("party/party_name") != HIC"ؤ��"NOR)
	{
		command("say ����"+ob->query("party/party_name")+"���ˣ���ô������Ҫؤ���ְ˾��");
		me->kill_ob(ob);
		return 0;
	}
	if ( ob->query_temp("have_cloth") && present("po bu", ob) )
	{
		command("say ��Ȼ�������͵��μǰ�棬Ϊ�������");
		message_vision("$N���Ʋ�����$n�����·��ϣ�ٲȻһ���¿ڴ���\n", me, ob);
		ob->delete_temp("have_cloth");
		newtitle=ob->query("title");
		switch (ob->query("beggarlvl"))
		{
			case 0:
				ob->add("combat_exp",250);
				ob->set("party/party_name", HIC"ؤ��"NOR);
				ob->set("party/rank", BLU"һ������"NOR);
				ob->set("party/level", 1);
				break;
			case 1:
				ob->add("combat_exp",500);
				ob->set("party/party_name", HIC"ؤ��"NOR);
				ob->set("party/rank", HIB"��������"NOR);
				ob->set("party/level", 2);
				break;
			case 2:
				ob->add("combat_exp",1000);
				ob->set("party/party_name", HIC"ؤ��"NOR);
				ob->set("party/rank", MAG"��������"NOR);
				ob->set("party/level", 3);
				break;
			case 3:
				ob->add("combat_exp",1500);
				ob->set("party/party_name", HIC"ؤ��"NOR);
				ob->set("party/rank", HIM"�Ĵ�����"NOR);
				ob->set("party/level", 4);
				break;
			case 4:
				ob->add("combat_exp",2000);
				ob->set("party/party_name", HIC"ؤ��"NOR);
				ob->set("party/rank", YEL"�������"NOR);
				ob->set("party/level", 5);
				break;
			case 5:
				ob->add("combat_exp",3000);
				ob->set("party/party_name", HIC"ؤ��"NOR);
				ob->set("party/rank", HIY"��������"NOR);
				ob->set("party/level", 6);
				break;
			case 6:
				ob->add("combat_exp",4000);
				ob->set("party/party_name", HIC"ؤ��"NOR);
				ob->set("party/rank", GRN"�ߴ�����"NOR);
				ob->set("party/level", 7);
				break;
			case 7:
				ob->add("combat_exp",5000);
				ob->set("party/party_name", HIC"ؤ��"NOR);
				ob->set("party/rank", HIG"�˴�����"NOR);
				ob->set("party/level", 8);
				break;
			case 8:
				ob->add("combat_exp",6000);
				ob->set("party/party_name", HIC"ؤ��"NOR);
				ob->set("party/rank", RED"�Ŵ�����"NOR);
				ob->set("party/level", 9);
				break;
		}
		ob->set("beggarlvl", ob->query("party/level"));
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
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

