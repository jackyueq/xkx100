// /guanwai/chuanchang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ��򴬳���������λ�ڹ����ƽԭ�в���һ�����ϵ�С��
���������ϡ������������Ը�ǽ���������ڼ��ء��������ɻ��������
�գ��˱��ұ�����Ҫ�ء��ɻ����ڶ���ʱ�����ͨ�У����ﻯ����ֻ��
�Ҵ��Ұ�æ�ˡ�
LONG );
	set("exits", ([
		"south"  : __DIR__"xuedi3",
		"east"   : __DIR__"bingmian",
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("outdoors", "guanwai");
	set("coor/x", 6080);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	object obj, *ob;
	int i,j;

	if (dir=="east")
	{
		if ((strsrch(NATURE_D->game_time(), "һ��") >= 0) ||
			(strsrch(NATURE_D->game_time(), "����") >= 0) ||
			(strsrch(NATURE_D->game_time(), "����") >= 0) ||
			(strsrch(NATURE_D->game_time(), "����") >= 0) ||
			(strsrch(NATURE_D->game_time(), "����") >= 0))
		{
			message_vision("$N������ᶳ����׳���Ӳȱ�������\n\n", me);
			if (random(me->query_dex())<20)
			{
				me->receive_wound("qi",20);
				me->receive_damage("qi",20);
			message_vision("$Nֻ���ý���һ����ȫ���ڿն��𣬽��ʵʵ��ˤ���˱����ϣ�\n", me);
			}
			return 1;
		}
		else
		{
			j = 0;
			ob = all_inventory(environment(me));
			for(i=0; i<sizeof(ob); i++)
			{
				if ( (!userp(ob[i])) && (ob[i]->query("id")=="chuan fu"))
					j = 1;
			}
			if (j == 0)
			{
				obj = new(__DIR__"npc/chuanfu");
				obj -> move(environment(me));
			message_vision("�������߳�һ�����򣬵����ۿ���$N��", me);
			}
			else
			message_vision("�������Ա����۵���$N����", me);
			return notify_fail("���滯�������ǳ˴��ɣ�\n");
		}
	}
	return 1;
}
