// qingke.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "���ƺ");
	set("long", @LONG
�߹���᫵�ʮ���̣��������ţ��͵������ƺ�����ƺ��һɽ����
�أ�������Ϊƽ̹�������￪ʼ����ɽ��·������ԭ�������ʯ�ס�Զ
Զ����һ��ССʯͤ�����Ƕ���ͤ�ˡ��ഫ��̫���뻪��������������
�ˣ�����ɽ��Ϊ��ע����̫�����ˣ��Ӵ˻�ɽ�ϵ����ؾͲ������Ǯ����
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"eastup"    : __DIR__"huixinshi",
		"northdown" : __DIR__"yunmen",
	]));
	set("objects",([ 
		__DIR__"npc/tao-jun" : 1,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -910);
	set("coor/y", 240);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
 
