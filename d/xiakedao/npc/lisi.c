// /d/xiakedao/npc/lisi.c ���ģ�����ʹ��
// Modified by Zeratul Jan 11 2001 ��Ϊ�����Ȼ�������

inherit NPC;
#include <ansi.h>
int inquiry_jiu();

void create()
{
	set_name("����", ({ "li si" , "li" , "si" }) );
	set("nickname", BLU"����ʹ��"NOR);
	set("gender", "����" );
	set("age", 30);
	set("long", "ֻ����������ߣ�ʮ��������������ɫ���ۣ�һ���Ŀ���\n");
	set("attitude", "friendly");
	set("shen_type", 0);

	set_temp("Ұ��/forleg", 0);
	set("no_get",1);

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

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
	    "���Ĵ��������ţ��þƣ����Ǻþƣ����ǾƷ�֪��ǧ���ٰ���\n",
	    "���������죺��ϧ�����¾ƣ���������ˬ��\n",
	    "����б������˵������վ�����ô�أ��ѵ�Ҳ������ֵ�����һ�����ɣ�\n"
	}) );
	set("inquiry",([
	   "��"     : (: inquiry_jiu :),
//	   "here"   : "���ﵱȻ�������͵�����",
//	   "������" : "�������ߣ���ɽ��������ˡ�",
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
		message_vision("���ĵ���˵�����Ʋ����Ѿ�����������λ"+RANK_D->query_respect(me) + "��Ҫ̰�����ᡣ\n", me);
		return 1;
	}
	if( !me->query_temp("xkd/backleg") )
	{ 
		message_vision( "���ĵ���˵������λ"+RANK_D->query_respect(me)+"������Ϊ����ʲô�ƣ��Ƕ���ͷ��������ô����Ķ����������������ء�\n", me);
		return 1;
	}
	if( !me->query_temp("xkd/forleg") )
	{ 
		message_vision( "���ĵ���˵������λ"+RANK_D->query_respect(me)+"����Ҫ���һ��ú��ҵ��ֵ�����һ�¡�\n", me);
		return 1;
	}	
	if( query_temp("Ұ��/backleg") || random(10) > 5 ) 
	{ 
		message_vision( "���ĵ���˵������λ"+RANK_D->query_respect(me)+"���ò��ɣ������Ѿ����˱����ˡ�\n", me);
	}
	else
	{
		message_vision( "���������˵������λ" + RANK_D->query_respect(me)+"����Ȼ����ҵĶ��ƣ��ðɣ����е��ӾͺȰɣ������ɱ��ڡ�\n",me);
		obn = new( "/clone/medicine/nostrum/binghuojiu" );
		obn->move( me );
		me->set_temp( "xkd/jiu", 1 );
	}
	set_temp( "Ұ��/backleg", 1 );
	return 1;
}

int accept_object(object who, object ob)
{
	object me;
	me=this_object();
	if( ob->query("money_id")  )
	{
		command("say " + RANK_D->query_respect(who) +
		"����Ϊ���Ǹ���ȱǮ���𣿸�����ɣ������ѻʹ�����" +
		"�������챦���ڵ�����ǰ����Ҳ���������" );
		return 0;
	}
	if (ob->query("id")=="bone")
	{
	       command(" say " + "�����ˣ���Ȼ�������ֶ�����ϷŪ���ӡ�����������·�㲻�ߣ�����������ƫ����\n");
	       me->set_leader(who);
	       me->kill_ob(who);
	       who->fight_ob(me);
	       return 0;
	}
	if( ob->query("id")=="back leg")
	{
	       who->set_temp("xkd/backleg", 1);
	       return 1;
	}
	return 0;

}
