// Room: /binghuo/wangpanshan.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����ɽ��̲");
	set("long", @LONG
ֻ���õ��ϺŽ�֮�����ش��𣬰������˸��ٴ��죬����ʾ�⡣
ֻ����������Ͼ�����һͷ��ӥ��˫����չ���������䡣�������֮
��վ��һ�����ߡ�ֻ��������˵����������̳�׹��ٹ�ӭ��͡�����
���������������ܣ��䲻������ȴ�����ϴ���������һ��ɽ�ȡ�
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("exits", ([
		"south" : __DIR__"wangpangu1",
		"east"  : __DIR__"wangpanlin",
	]));
	set("objects", ([
		"/d/mingjiao/npc/baiguishou" : 1,
	]));
	setup();
	replace_program(ROOM);
}

