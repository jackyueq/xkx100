// Room: /d/yanping/fuqiao1.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "ˮ������");
	set("long", @LONG
��ƽ����ɽ��ˮ�ƣ�ʫ����ɽΧ�����̣�ˮ�ƶ����ࡱ����Ϫ����
Ϫ�ִӱ��������滷�Ƴǹ����ٻ㼯��ȥ���˸��ű��Ǽ����ڽ�Ϫ�ϵ�
���ñؾ�֮���ˡ����и����ɼ�ʮ��С�������������ɣ������ٸ���ľ
�壬��������ͨ�С�
LONG );
	set("exits", ([
		"eastup" : __DIR__"mazhan",
		"westup" : __DIR__"dongmen",
	]));
	set("outdoors", "yanping");
	set("coor/x", 1530);
	set("coor/y", -6170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
