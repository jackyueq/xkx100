// Room: /d/huanggong/lou2.c

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
��¥������һ��������ķ�ͤ¥, �ĳ�����. ���ʮ�ּ��ƽ�
������, ����������, ����, ʮ����, ��ʮ������, �����ص�, �ݺύ
��. �����ǰ���ʯ̨����Χ���԰�������. �������ڳ�һ��, �ܿ�����
��, �ڳ��ĽǸ���һ�������Ľ�¥, ���з紵�ݶ�, ����һ�����.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"jiao2",
	]));
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 5260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}