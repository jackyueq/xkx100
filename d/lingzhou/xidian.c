// Room: /d/lingzhou/xidian.c

inherit ROOM;

void create()
{
	set("short", "��ƫ��");
	set("long", @LONG
��������ƫ��ǻ����ϳ��Ǳؾ�֮�����������µ�ʱ�������Ǿ�
��������š��ذ��ǰ����̳ɣ������ǰ�ɫ���ᢡ����������ͨ����
�´�������һ������ͨ�����鷿���޹��������ǽ�����������Ȼ�
�Ļ���������һ����س�������������������ѻȸ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"yushufang",
		"east" : __DIR__"huilang",
	]));
	set("objects", ([
		__DIR__"npc/neishi" : 2,
	]));
	set("coor/x", -17970);
	set("coor/y", 32106);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
