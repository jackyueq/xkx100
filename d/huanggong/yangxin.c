// Room: /d/huanggong/yangxin.c

inherit ROOM;

void create()
{
	set("short", "���ĵ�");
	set("long", @LONG
���ĵ��ǻʵ۾�ס�ʹ����ճ�����ĵط�. �ڱ�ǽ��������һ����
��(bian), ������������Ǭ¡��������(zi). ��ů������ʥ��ʥѵ����
��ʥѵ������. ��ů����,  "��������" �����, ��һ�����ڵ������
��(lian). ����ҲһЩ��Ա��ѡ��, ����ǰ��������ʥ�ĵط�. �����
�����һЩ�����ϻʵ�������ҵľ��顢��ѵ���鼮, �ǹ�С�ʵ�ѧϰ
��.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"yuehua",
	]));
	set("item_desc", ([ /* sizeof() == 2 */
		"bian"  : "
�����ʺ�\n\n",
		"zi"  : "
��̩������
��Ԫ�����\n\n",
		"lian"  : "
Ω��һ��������
��Ϊ���·�һ��\n\n",
	]));
	set("no_clean_up", 0);

	set("coor/x", -220);
	set("coor/y", 5280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}