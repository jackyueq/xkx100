// Room: /d/quanzhou/gushaota.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ɩ��");
	set("long", @LONG
��ɩ������������������Ρ��ͦ�Ρ�����Զ��������Ħ����ǧɽ
�����������ٵ�ͨ�����ഫ��ʱ��һ�������ӣ����ޱ��ã�Զ������
���Ϻ�Ϳ���磬���۾�������ɩ����̨Զ�����ո�һ�գ���˼�ɼ���˫
˫���������˽������������ˡ�ͬʱ����Ҳ��Ȫ�ݸ���Ҫ�ĵ�������
�����ǰ����ۣ��������������ۡ�
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"west"  : __DIR__"anhaigang",
		"north" : __DIR__"yongninggang",
	]));
	set("objects", ([
		__DIR__"npc/langren" : 1,
	]));
	set("coor/x", 1870);
	set("coor/y", -6630);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
