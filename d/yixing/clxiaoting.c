// /d/yixing/clxiaoting.c
// Last Modified by winder on Jul. 12 2002

#include <changle.h>
#define WOSHI   BANGS"clwoshi"
#define BANGZHU BANGS"npc/cl_situ"
inherit ROOM;
#include D_BEAUTY

void create()
{
	set("short", "С��");
	set("long", @LONG
���ǰ������ܹ����ֻ��ܴ��µ����ڣ�������һ��̫ʦ�Σ����ϵ�
�Ű�ɵĺ��������ǽ�ϸ�ӹ���ŵع��ż���ɽˮ�ֻ���һ����֪����
����֮������ǰ����ջ�����ʮ�ַ�ï��
LONG );
	set("exits", ([
		"south" : __DIR__"clzoulang2",
		"north" : __DIR__"clwoshi",
	]));
	set("objects",([
		__DIR__"npc/cl_situ" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	string beauty;
	object ob, leader, ling, *inv;
	int bonus, record;

	if( dir != "north" )
		return ::valid_leave(me, dir);
	if( !(ob = present("situ heng", environment(me))) )
		return ::valid_leave(me, dir);
	if( !living(ob) )
		return ::valid_leave(me, dir);

	if( ob->is_fighting() || ob->is_busy() )
		return notify_fail(sprintf("%s��������ǰ���ȵ���" + RANK_D->query_rude(me) + "��������û��������æ�ţ�\n", ob->name()));

	if( stringp(beauty = me->query_temp("bangs/beauty")) )
	{
		inv = all_inventory(this_object());
		for(int i = 0; i < sizeof(inv); i++)
		{
			if( (string)inv[i]->query("name") == beauty &&
				inv[i]->query_leader() == me )
			{
				message_vision("$N��$n��ͷ�ϵ��˸������Ա�����$n�����Ŷ������̳����˸�С������\n", ob, me);
				return ::valid_leave(me, dir);
			}
		}
	}

	if( !userp(me) )
	{
		beauty = (string)me->query("name");
		if( intp(bonus = info_beauty[beauty]) &&
			leader = me->query_leader() )
		{
			if( userp(leader) &&
			(string)leader->query_temp("bangs/beauty") == beauty )
			{
				tell_object(leader, ob->name() + "˵�����ã��ã��ã�"+ob->query("party/party_name") + "�������¼�ǧ�����������ְ����Ļ��ģ�\n");
				leader->delete_temp("bangs/beauty");
				bonus = bonus * 25000 / (100000 + (int)leader->query("combat_exp"));
				record = bonus + random(bonus);
				leader->add("combat_exp", record);
				leader->add("shen", -record);
				write_file("/log/test/BangWomen",  sprintf("%s��%sʱ�Ϲ�%s��%s�����\n", leader->query("name"), ctime(time()), beauty, chinese_number(record)));
				if( ling = present("bang ling", leader) )
				{
					if( (string)ling->query("owner") ==
						leader->query("id") )
						ling->add("score", bonus/2 + random(bonus/2));
				}
				me->set_leader(0);
				remove_call_out("destroy_beauty");
				call_out("destroy_beauty", 1, me, leader);
				return ::valid_leave(me, dir);
			}
		}
	}
	return notify_fail(sprintf("%s��������ǰ���ȵ���" + RANK_D->query_rude(me) + "�������񣡺����ǰ������Է���\n", ob->name()));
}

void destroy_beauty(object me, object leader)
{
	object room, ob;

	if( !me ) return;

	if( !leader ) { destruct(me); return; } 

	room = environment(me);
	if( base_name(room) != WOSHI ) { destruct(me); return; }
	if( room != environment(leader) ) { destruct(me); return; }
	if( !(ob = present("shijian", room)) ) { destruct(me); return; }
	if( !living(ob) ) { destruct(me); return; }
	message_vision("$N��$n�ȵ�����Ҫ����λС����£�����ȥ�ɣ�\n", ob, leader);
	message_vision("$N����һ�Ž�$n���˳�ȥ��\n", ob, leader);
	leader->move(this_object());
	message("vision", leader->name() + "���˴��Է������˳������Ǳ�������\n", this_object(), ({leader}));

	destruct(me);
}
