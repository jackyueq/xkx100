// Room: /d/wuyi/tianchejia.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "�쳵��");
	set("long", @LONG
�쳵��Ҳ�ƹ��¾ӣ�λ�ӵ�ϼ���ϡ�������̷��������ʿ��Ϊ��
��̫ƽ����������Ǳڵĵ�ϼ�ֵ�ʮ���ɸߴ����ı�����������������
һ��϶�Ҷ��������С¥�������У���������Χ���͵��ܣ����ݰ���
�ˡ�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"path15",
		"south" : __DIR__"path13",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -4900);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

