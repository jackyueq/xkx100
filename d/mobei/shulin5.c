// Room: /d/mobei/shulin5.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��Į����Ƭ�ຮ�������ϣ���Ƭ����������ɳĮ�е����ݰ����˾�
ϲ�����Ӳ�����ľҲ�Ƚϰ�С�����ط��Ĺ�ľ�԰�·��ȫ��ס�ˣ�
���ϲ����ļ�ƬҶ���ڷ�������Ʈ�䡣
LONG);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"caoyuan1",
		"south" : __DIR__"shulin2",
	]));
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("coor/x", -230);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
