// Room: /d/yangzhou/qianzhuang.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "����Ǯׯ");
	set("long", @LONG
����Ǯׯ�ǽ��ϵ����ֺ��ˣ���ۡ�ҵ�һ����ۡ�������������Ǯ
ׯ�󴫵����ڣ��Ѿ����ϰ������ʷ�ˡ�����Ǯׯӡ������Ʊ����Ǯׯ
�����һ�������ͨ�ã��������á�Ǯׯ���򵥵�����һ����̨������
��ƺ��ʷ��������ں��棬��ʱ�����ڴ˴�Ǯ����Ǯ�����Ϲ��Ÿ�����
(paizi)��
LONG );
	set("exits", ([
		"east" : __DIR__"shilijie5",
	]));
	set("item_desc", ([
		"paizi" : @TEXT
     ��Ǯׯ�ṩ���·���
      ��Ǯ        deposit����cun
      ȡǮ        withdraw����qu
      Ǯ�Ҷһ�    convert����duihuan
      ����        check����chazhang
TEXT
	]) );

	set("objects", ([
		__DIR__"npc/qian" : 1
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	set("coor/x", 0);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}