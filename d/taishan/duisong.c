// Room: /d/taishan/duisong.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����������ȥ�����Ƕ���ɽ������ɽ˫����ţ��������꣬�Դ���
��������������������ɽ���ɺ����Ƴ���䣬���ç�������������
���δ�����������ۡ�����С��������ƺ���Զ����ӯ�ߡ���ʫ�䡣Ǭ
¡��ơ������Ѵ�����������桱��
LONG );
	set("exits", ([
		"southdown" : __DIR__"chaoyang",
		"northup"   : __DIR__"kaishan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 700);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}
