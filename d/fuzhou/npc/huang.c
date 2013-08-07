// huang.c

#include <ansi.h>

inherit NPC;
inherit F_SKILL;
int ask_diubiao();

void create()
{
	set_name("������", ({ "huang xiansheng", "huang" }));
	set("title", HIR"��"HIC"��"YEL"�ھ�"HIY"�˷�"NOR);
	set("gender", "����");
	set("age", 36);

	set("inquiry", ([
		"����" : (: ask_diubiao :),
		"ʧ��" : (: ask_diubiao :),
		"ʧ��" : (: ask_diubiao :),
	]) );

	set("combat_exp", 10000);
	set("shen_type", 1);

	set("eff_qi",800);
	set("qi",800);
	set("max_neili", 100);
	set("neili", 100);
	set("jiali", 10);


	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
	object myenv ;
	if(who->query_temp("fuwei_diubiao_ask")&&(ob->query("money_id") && ob->value() >= 100000))
    {
		message_vision(HIY"����������$N˵���ðɣ����ٸ���һ�λ����ˣ�\n"NOR , who);
	    who->delete_temp("fuwei_destm");
	    who->delete_temp("fuwei_dest");
	    who->delete_temp("fuwei_diubiao_ask");
	    who->delete_temp("fuwei_ready");
            who->delete_temp("fuwei_prepare");
            return 1;  
         }
	if(who->query_temp("fuwei_ready"))
	{
		message_vision(HIY"����������$N˵���ָ���Ǯ���ã��ã������Һ��Ͼƣ�\n"NOR , who);
		return 1;
	}
	if(!who->query_temp("fuwei_prepare"))
	{
		message_vision(HIY"����������$N˵��ҪѺ�ڣ�����ȥ������ͷ��\n"NOR, who);
		return 1;
	}
	if ( wizardp(who) || (ob->query("money_id") && ob->value() >= 200000))
	{
		message_vision(HIY "����������$N˵���ڳ�׼�����ˣ���Ժ�����ء��Ͽ����(jiebiao)�ɣ�\n������Ѻ����⳥��������\n"NOR , who);
		who->set_temp("fuwei_ready",1);
		who->delete_temp("fuwei_prepare",1);
		return 1;
	}
	else
	{
		message_vision(HIR"������������ü��$N˵������㣿�㻹��ʲô�ڣ���ȥ��ȥ��\n"NOR, who);
		return 0;
	}
}

int ask_diubiao()
{ 
	object me = this_player();
	if (me->query_temp("fuwei_dest"))
	{
message_vision(HIR"������������ü��$N˵������������кü�������������Ҫ����������ھ��Ƚ�ʮ���ƽ����ɣ�\n"NOR, me);
        me->set_temp("fuwei_diubiao_ask",1);
        return 1;
	}
        else 
        {
          message_vision(HIR"��������ü��:�����û�ӹ��ڰɣ�\n",me);
          return 1;
        }
          
}
