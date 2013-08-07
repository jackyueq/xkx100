// laoban.c 
#include <ansi.h>;
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�ϰ���", ({"laoban niang", "laoban"}));
	set("age", 32);
	set("gender", "Ů��");
	set("per", 20);
	set("attitude", "friendly");

	set("combat_exp", 400);
	set_skill("unarmed", 10);
	set_skill("dodge", 10);

	set("vendor_goods", ({
		__DIR__"obj/meigui",
		__DIR__"obj/mudan",
		__DIR__"obj/chahua",
		__DIR__"obj/lanhua",
		__DIR__"obj/meihua",
		__DIR__"obj/redrose",
		__DIR__"obj/yaohuang",
		__DIR__"obj/weizi",
	}));
	set("chat_chance", 20);
	set("chat_msg", ({
		"�ϰ���̾��������ͬ��һ�㣬һ�첻��һ���ˡ�\n",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 2);
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_send", "send");
}
int do_send(string arg)
{
	object obj, flower, me = this_player();
	string target, item;

	if(!arg) return notify_fail("�ϰ���˵����Ҫ��˭ʲô������\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	if( sscanf(arg, "%s to %s", item, target) !=2)
		return notify_fail("�ϰ���˵����Ҫ��˭ʲô������\n");

	obj = find_player(target);
		if(!obj || !me->visible(obj))
			return notify_fail("�ϰ���˵���������ڲ��ڡ�û�������ͻ���\n");

	if( !living(obj))
		return notify_fail("�ϰ���˵����Ǹ������û�������ͻ���\n");

	if( !objectp(flower = present(item, me)) )	
		return notify_fail("�ϰ���˵��������û�����ֻ���\n");

	if( !flower->query("flower"))
		return notify_fail("�ϰ���˵����ֻ�����Ұ����ͻ���\n");

	if( flower->query("no_drop") )
		return notify_fail("�����������������ˡ�\n");

	flower->move(obj);
	me->save();
	obj->save();
	tell_object(me, HIC"�����ϰ���Ц��Ц��������λ"+RANK_D->query_respect(me)+"�Ժ���͸����͵�"+obj->query("name")+"���ϡ���ת�����ȥ�ˡ�\n" NOR );
	tell_object(obj, HIC"�����ϰ����߹����ݸ���һ"+flower->query("unit")+flower->query("name")+HIC"������˵����������"+me->query("name")+"�͸���ġ���ת��Ц��Ц�����ˡ�\n" NOR );
	tell_object(me, HIC"�����ϰ���Ƭ�̺����Ц���������İɣ��͵��ˡ���\n" NOR );
	return 1;
}
