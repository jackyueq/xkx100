// Room: /d/mobei/caoyuan6.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "��ľ�沿��");
	set ("long", @LONG
��ľ�沿���ǵ����ɹŲ�ԭ����ǿʢ��һ�壬������������ı����
�����ˣ���ԭ�ϵ�Ӣ�۶�Ը��Ϊ��Ч������Ŀ������֮����ţ����׳��
������ɹŰ��ڸ��˾�Ŀ���������Ĳ�ԭ��
LONG);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 3 */
		"northeast" : __DIR__"buluo",
		"southwest" : __DIR__"caoyuan5",
		"west"      : __DIR__"shulin1",
	]));
	set("coor/x", -220);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
