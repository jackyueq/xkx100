// Room: /beijing/qianzhuang.c

inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ
�����е���Ʊ�����ǳ��ã�ͨ��ȫ�����������ߵ�������κ�һ����
ׯ�ֵ궼���������ȡ��ǽ�Ϲ���һ������(paizi)��
LONG );
	set("item_desc", ([
        "paizi" : "\n��ׯ����Ϣ�����ٰٷ�֮һ��\n
      ��Ǯ        deposit����cun\n
      ȡǮ        withdraw����qu\n
      Ǯ�Ҷһ�    convert����duihuan\n
      ����        check����chazhang\n",
	]));
	set("exits", ([
		"west" : __DIR__"wangfu1",
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	set("objects", ([
		CLASS_D("yunlong")+"/qianlaoben" : 1
	]));

	set("coor/x", -170);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
