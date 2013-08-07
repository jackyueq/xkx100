// /d/xiakedao/npc/zhangsan.c ���� ����ʹ��
// Modified by Zeratul Jan 11 2001 ��Ϊ�����Ȼ�������

inherit NPC;
int inquiry_jiu();
#include <ansi.h>
void create()
{
	set_name("����", ({ "zhang san" , "zhang" ,"san" }) );
	set("nickname", HIR"����ʹ��"NOR);
	set("gender", "����" );
	set("age", 30);
	set("long", "ֻ������Ŀ��࣬Բ���������һϮ��ͭɫ���ۣ�Ц������һ���Ͱ����ס�\n");
	set("attitude", "friendly");
	set("shen_type", 1);

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set_temp("Ұ��/forleg", 0);
	set("no_get",1);
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 2000000);
	set("score", 20000);
	set_skill("parry", 200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("taixuan-gong", 200);
	map_skill("parry", "taixuan-gong");
	map_skill("force", "taixuan-gong");
	map_skill("dodge", "taixuan-gong");
	map_skill("unarmed", "taixuan-gong");

	set("chat_chance",3);
	set("chat_msg",({
	    "�������������ţ��þƣ����Ǻþƣ����Ǿ��ˣ�\n",
	    "���������죺��ϧ�����¾ƣ���֪��û�еط�Ū��������\n",
	    "����������Ц�ض���˵������վ�����ô�أ��ǲ�������ֵ��Һ�������\n"

	}) );
	set("inquiry",([
		"��" : (: inquiry_jiu :),
		"������":"\nȥ���������������Ե�ְɡ�\n",
		"ʯ����":"\n�����ҵĽ���ֵ�ѽ����Ҳ�����ء�\n",
		"���Ʒ�����":"\n���������ֵܵ����\n",
//		"here" : "���ﵱȻ�������͵���",
//		"������" : "�������ߣ���ɽ���������",
	]) );
	create_family("���͵�", 2, "����");
	setup();
}

int inquiry_jiu()
{
	object me=this_player();
	object obn;

	if ( me->query_temp( "xkd/jiu" ) )
	{ 
		message_vision("����Ц�����Ʋ����Ѿ�����������λ" + RANK_D->query_respect(me) + "��Ҫ�������ֵܵ���Ц��\n", me);
		return 1;
	}
	if( !me->query_temp("xkd/forleg") )
	{ 
		message_vision( "����Ц������λ"+RANK_D->query_respect(me)+"���ⲻ�Ǿơ�������С�����ⶫ����ɺȲ��õġ�\n", me);
		return 1;
	}
	if( !me->query_temp("xkd/backleg") )
	{ 
		message_vision("����Ц�����ã��á������һ��ú��ҵ��ֵ�����һ�¡�\n",me);
		return 1;
	}	
	if( query_temp("Ұ��/forleg") || random(10) > 8 )
	{ 
		message_vision( "����Ц������λ"+RANK_D->query_respect(me)+"���ò��ɣ������Ѿ����˱����ˡ�\n", me);
	}
	else
	{
		message_vision( "����̾����˵����λ"+RANK_D->query_respect(me)+"����Ϊʲôһ��Ҫ������أ�������δ���кô���\n�ðɣ���Ȼ��Ҫ���͸���ɣ�������ҪС�İ���\n",me);
//�������������һ�����ɫ�ĺ�«�����˸��㡣\n" , me);
		obn = new( "/clone/medicine/nostrum/binghuojiu" );
		obn->move( me );
		me->set_temp( "xkd/jiu", 1);	
	}
	set_temp( "Ұ��/forleg", 1);
	return 1;
}

int accept_object(object who, object ob)
{
	object me;
	me=this_object();
	command("smile");
	if( ob->query("money_id") )
	{
		command("say " + RANK_D->query_respect(who) +
			"��л��ĺ��⣬���Ǹ�����ȱǮ����Ǯ������Ҫ�����ж��١�" );
		return 0;
	}
	if (ob->query("id")=="bone")
	{
		command(" say " + "���ֺο࿪����Ц�أ���Ҫ�����ֵ����Ŀ����ˣ�����ɱ���㲻�ɡ�\n");
		return 1;
	}
	if( ob->query("id")=="for leg")
	{
//	    set_temp("Ұ��/forleg", 1);
		who->set_temp( "xkd/forleg" , 1 );
		return 1;
	}
	return 0;
}
