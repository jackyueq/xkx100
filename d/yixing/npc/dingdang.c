// /d/yixing/npc/dingdang.c ��������
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void init();

string ask_wine();
string ask_tian();

void create()
{
	set_name("����" , ({"ding dang", "ding"}));
	set("long",
		"ֻ������ǰ������һ��������������ӣ�С��ߴ�����Ƥ��΢Ц��\n"
		"������ɢ������Ů�����㣬�������˲�������һ����\n");
	set("nickname", HIC"��������"NOR);
	set("gender", "Ů��");
	set("attitude", "friendly");
	set("age", 18);
	set("per", 27);
	
        set("str", 18);
        set("int", 26);
        set("con", 20);
        set("dex", 19);
        
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 700);
        set("max_jing", 700);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 10);

        set("combat_exp", 70000);
        set("score", 70000);

	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("hand", 85);
/*
	set_skill("taixuan-gong", 70);
	set_skill("ding-dodge", 70);
	set_skill("dingjia-qinnashou", 80);
	set_skill("literate", 60);
	
	map_skill("force", "taixuan-gong");
	map_skill("parry", "dingjia-qinnashou");
	map_skill("hand", "dingjia-qinnashou");
	map_skill("dodge", "ding-dodge");
	prepare_skill("hand", "dingjia-qinnashou");
*/	
	set("inquiry", ([
		"�����̻��" : (:ask_wine:),
		"wine" : (:ask_wine:),
		"������" : "����������үү�������������£���үү���׵ģ��㻹�Ǳ������ˡ�\n",
		"���" : (:ask_tian:),
		"ʯ����" : (:ask_tian:),
		"ѩɽ��" : "үү������ѩɽ�ɵ����ˣ���ǧ��Ҫ������ǰ����\n",
		"xueshan" : "үү������ѩɽ�ɵ����ˣ���ǧ��Ҫ������ǰ����\n",
		"name" : "���ն���������Ҷ����Ҷ���������\n",
		"����" : "���ն���������Ҷ����Ҷ���������\n",
	]));
	
	setup();
	carry_object(CLOTH_DIR"female-cloth")->wear();

}

void init()
{
	object ob, me;
	me=this_player();
	
	if ( environment(me)==find_object("/d/forest/clbajiaoting.c")) {
	if ( me->query_temp("find/dddd"))
	{
	command("say �����˲�֪��ʲôʱ���ȫ��������˵��ġ�");
	command("sigh");
	return;
		}
	}
}

string ask_tian()
{
	object me=this_player();
	
	if ( me->query_temp("find/dddd"))
	{
	command("sigh");
	return "����������ˣ��Ҹ�ι�˵㡸�����̻�ơ��������ã�ϣ����û�¡�";
	}
	else {
	return "��Ҳ��ʶ������ޣ����ˣ������������°ɡ�";
	}
}

string ask_wine()
{
	object me=this_player();
	
	if (me->query("combat_exp") < 100000)
	{
	command("look  "+me->query("id"));
	command("sneer "+me->query("id"));
	return "ƾ����㱾�������ܱ���������£���";
	}
	if ( me->query_temp("find/dddd"))
	{
	command("ah "+me->query("id"));
	add_action("do_pretty", "pretty");
	command("say һ����үү������Ȱ�һ�ȥ���ǲ��ǣ�ԭ�����Ѿ�֪����͵�����ı�����");
	command("sigh");
	command("say �����ǰ�������ʣ����˼�������ǻ�����ģ����������֪����ô��ɵ�ˣ������˼ҵĻ�Ҳ����˵�ˡ�");
	command("disapp");
	me->set_temp("pretty/ding", 1);
	return "������Ը������ǰ�Ǹ�����˼ҿ��ĵ���硣";
	}
	else {
		return "�������үү�ģ����Լ�����Ҫ�ɡ�";
		}
}

int do_pretty(string arg)
{
	object me, ob, *obs;
	me=this_player();
	
	if ( !arg ) return 0;

	ob = present(arg, environment());
        
	if (!objectp(ob)) return 0;
        
	if (me->query_temp("pretty/ding")) 
        {
        command("giggle");
        command("happy2 "+me->query("id"));
        command("blush");
        command("say лл������������Ҫ������������磬����Ұ���ʣ�µġ������̻�ơ�����ȥ��үү�ɡ�");
        ob=new("/clone/unique/jiu.c");
	message_vision("������һƿ�������̻�ơ����˸�$N��\n", me);
	ob->move(this_player());
	me->set("got/wine", 1);
	me->delete_temp("find/dddd", 1);
	me->delete_temp("pretty/ding", 1);
	me->delete_temp("first/ask");
        return 1;
	} 
}
