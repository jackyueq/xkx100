// Room: /heizhao/pububian.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ٲ�����");
	set("long", @LONG
�ٲ���ҹ�����������¾ã�����ʯ������һ�����Լ�ж���
���ߡ�վ�ڰ��ϣ�ֻ�����ٲ����ڶ�ȥ��ˮĭ�Ľ������ɵ�Ŀѣ��
�����ٲ�һк��ע��ֱ����������Ԩȥ������ϵ��һֻ���ۡ�
LONG );
	set("outdoors", "taoyuan");
	set("resource/water", 1);
	set("exits", ([
		"south" : __DIR__"xiaowu",
		"enter" : __DIR__"ironboat",
	]));
	set("coor/x", -5020);
	set("coor/y", -1260);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}