// Room: /binghuo/wangpangu1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ȿ�");
	set("long", @LONG
�߽�ɽ�ȣ�ǰ�����Ͼ���Ⱥ�۾ۻ�֮��������ɽ������������Ϣ
֮�������羢�ң���������ȿ���۽������Ǵ�����ɽ��֦���裬ɳ
�����졣������ȥ��ֻ��ɽ����һƬ��ݵ��ϰ����߰��ŷ���������
���׵�һϯ�⣬ÿ�����Զ��������ˡ�
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("exits", ([
		"north" : __DIR__"wangpanshan",
		"south" : __DIR__"wangpangu2",
	]));
	set("objects", ([
		"/d/mingjiao/npc/changjinpeng" : 1,
	]));
	setup();
	replace_program(ROOM);
}

