// /d/meizhuang/xiaodao.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
���ߵ�����С·�ϣ�ǰ���Ѿ���������ԼԼ����һ��СС��Ժ���
Ӱ�ӣ�����Էǳ��Ŀ϶����������Ǵ����СԺ�﷢�����ģ��뵽����
�Ϳ��Լ�����ׯ�����ӹ��ˣ��㲻��һ����š� 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north"    : __DIR__"xiaoyuan",
		"westdown" : __DIR__"qhpo",
	]));
	set("outdoors", "meizhuang");
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1440);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
