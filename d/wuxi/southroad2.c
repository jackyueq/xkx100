// Room: /d/wuxi/southroad2.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�ϳ���");
	set("long", @LONG
�ϳ�����ס�������ͨ��С�����������̾������˶��У��Ե�ʮ
�ֵط�������ש�̳ɵĵ�·���ϱ���ͷ���졣���ߵ������鳡���в���
����ͷ�ˣ��Ǹ������ϰ�������ϲ��ȥ�ĵط��ˡ�����һ�������¥��
��ʱ�ش���������Ц���Ǿ���������������Ⱥ��Ժ�ˡ������ǿ�Խ�˺�
�������š�
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"sanfengqiao",
		"south" : __DIR__"southgate",
		"east"  : __DIR__"qunyu",
		"west"  : __DIR__"shuchang",
	]));
	set("objects", ([
			__DIR__"npc/lady2" : 1,
	]));
	set("coor/x", 370);
	set("coor/y", -830);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}