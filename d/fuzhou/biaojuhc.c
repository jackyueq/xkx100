// Room: /city/biaojuhc.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ھ��书���޳�ɫ֮���������ֵ�ͷ���ͺڰ������������ã�
��δʧ�ڡ������Ļ���������ѻ���ɽ���ھֵĻ����������æ���ҵ�
���ڳ���װ�ػ����Ȼÿ����ƶ��Ѿ�����Ϊ��������æ��������
LONG
        );
	set("exits", ([
		"west"  : __DIR__"biaojudy",
		"north" : __DIR__"biaojuzf",
	]));
	set("objects", ([
		__DIR__"npc/qian" : 1,
		__DIR__"npc/huo" : 1,
	]));
	set("coor/x", 1831);
	set("coor/y", -6298);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
