// Room: /d/yanping/fuqiao2.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "ˮ�ϸ���");
	set("long", @LONG
��ƽ����ɽ��ˮ�ƣ�ʫ����ɽΧ�����̣�ˮ�ƶ����ࡱ����Ϫ����
Ϫ�ִӱ��������滷�Ƴǹ����ٻ㼯��ȥ���˸��ű��Ǽ�������Ϫ��ͨ
���ϰ��ŷ�ɽ�ıؾ�֮�������и����ɼ�ʮ��С�������������ɣ�����
����ľ�壬����ͨ�С�
LONG );
	set("exits", ([
		"southup" : __DIR__"9fengshan",
		"northup" : __DIR__"yanshoumen",
	]));
	set("outdoors", "yanping");
	set("coor/x", 1480);
	set("coor/y", -6210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
