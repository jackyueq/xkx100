// Room: /d/taohua/neishi2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ɨҶ��");
	set("long", @LONG
�Ƶ����������ɨҶ���������ͣ�������ʰ��ʮ�����š�������
��͸��һЩЩ�һ�����ζ���Լ�һ��㺣ˮ��������ζ������һ�Ŵ���
���Ϸ��ż�������һ����飬���澡��һЩ��ֵķ��ţ��㿴������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"woshi2",
		"west"  : __DIR__"chufang",
		"south" : __DIR__"neishi1",
	]));
	set("outdoors","taohua");
	set("coor/x", 9000);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}