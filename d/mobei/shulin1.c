// Room: /d/mobei/shulin1
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "������");
	set ("long", @LONG
��Į����Ƭ�ຮ�������ϣ���Ƭ����������ɳĮ�е����ݰ����˾�
ϲ�����Ӳ�����ľҲ�Ƚϰ�С�����ط��Ĺ�ľ�԰�·��ȫ��ס�ˣ�
���ϲ����ļ�ƬҶ���ڷ�������Ʈ�䡣
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"shulin4",
		"east"  : __DIR__"caoyuan6",
		"south" : __DIR__"shulin3",
		"north" : __DIR__"shulin2",
	]));
	set("coor/x", -230);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
