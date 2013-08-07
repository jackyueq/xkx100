// Room: /d/taohua/xiaoyuan.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����СԺ");
	set("long", @LONG
û���뵽���ﾹȻ������ô���ŵ�СԺ����ɽ���ȣ������辰����
һ���Ƿ��õü�Ϊ���ʣ���Ȼ��������˷ǳ���Ϥ���ã�����ϵ������
������������һ������������ͨ�������С��仯����֮��������
һ��Сɽ�ԣ�ת��ɽ�Ծ���һ��Ƭ�Ĳݵء�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east"  : __DIR__"bagua1",
		"west"  : __DIR__"bagua0",
		"south" : __DIR__"taohua1",
		"north" : __DIR__"caodi",
	]) );
	set("objects",([
		CLASS_D("taohua")+"/feng" : 1,
		__DIR__"obj/shizi" : 1,
	]));  
	set("outdoors","taohua");

	set("coor/x", 9010);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
}
void init()
{
	object me=this_player();
	if (me->query_temp("step_count"))
	 me->delete_temp("step_count");
}
int valid_leave(object me, string dir)
{
	object *ob, *deep_ob;
	int i, j, drop_flag;

	if (dir == "west" || dir == "east")
	{
		if (!me->query_temp("bagua_1") &&
			me->query_skill("qimen-wuxing", 1) < 90)
			return notify_fail("��о�����һ����а��ذ��ԣ����������������������˻�����\n");
		ob = all_inventory(me);
		drop_flag = 0;
		for(i = 0; i < sizeof(ob); i++)
		{
			if (userp(ob[i]))
			{
				if (!drop_flag)
				{
					message_vision("$N���˿���ǰ��������ޱȵİ����󣬾������°�������װ����\n", me);
					drop_flag = 1;
				}
				message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, ob[i]);
				ob[i]->move(this_object());
			}
			else
			{
				deep_ob = deep_inventory(ob[i]);
				for(j = 0; j < sizeof(deep_ob); j++)
				{
					if (userp(deep_ob[j]))
					{
						if (!drop_flag)
						{
							message_vision("$N���˿���ǰ��������ޱȵİ����󣬾������°�������װ����\n", me);
							drop_flag = 1;
						}
				                message_vision(sprintf("$N����һ%s$n��\n", ob[i]->query("unit")), me, ob[i]);
						ob[i]->move(this_object());
						break;
					}
				}
			}
		}
	}

	return ::valid_leave(me, dir);
}