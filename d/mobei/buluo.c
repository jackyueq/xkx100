// Room: /d/mobei/buluo.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "��ľ�沿��");
	set("long", @LONG
��ľ�沿���ǵ����ɹŲ�ԭ����ǿʢ��һ�壬������������ı����
�����ˣ���ԭ�ϵ�Ӣ�۶�Ը��Ϊ��Ч������Ŀ������֮����ţ����׳��
������ɹŰ��ڸ��˾�Ŀ���������Ĳ�ԭ��
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 3 */
		"northwest" : __DIR__"buluo2",
		"north"     : __DIR__"buluo1",
		"southwest" : __DIR__"caoyuan6",
	]));
	set("coor/x", -210);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
