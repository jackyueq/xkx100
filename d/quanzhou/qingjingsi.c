// Room: /d/quanzhou/qingjingsi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�徻��");
	set("long", @LONG
����һ�����������Ǵ���ʿ����˹������ö����Ľ��ã�ȫ������
ɫ�Ͱ�ɫ�Ļ���ʯ���졣�ߴ����ζ��ļ⹰����ʹ����վ�����ڣ���
�С������®����ձ��֮�С����ڻ���һ���������͡�ʯ�̡����ź��
�����ǡ�����̳������������ͽ�ڴ��������ݡ�
    ����ϻ����С�����������
LONG );
	set("exits", ([
		"south" : __DIR__"tumenji",
		"north" : __DIR__"alabo",
	]));
	set("objects", ([
		__DIR__"npc/huihui" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6570);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
