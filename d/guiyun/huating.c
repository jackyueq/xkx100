// Room: /guiyun/huating.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���ķ��͵���ͤ��û�����ң���������ľ�������Ϲ��˷�ȱ
�˰��ڵġ�ʫ�ʡ�(poem)�����ڰ����˼������Ρ�һ��Ѿ����
��Ĩ�����档
LONG );
	set("outdoors", "guiyun");
	set("exits", ([
		"west"  : __DIR__"zoulang8",
		"south" : __DIR__"zoulang7",
	]));
	set("item_desc", ([
		"poem" :
"
      ������             ������
      ������             ��  ��
      ����             ��  ��
      ���Щ�             ��  ��
      ���ũ�             ��  ��
      ������             ��  ��
      ��ƶ��             ��  ��
      ���婦             ��  ��
      ���ũ�             ��  ��
      ������             ��  ��
      ���ҩ�             ��  ��
      ������             ������
",
	]));
	set("objects", ([
		__DIR__"npc/xiaolan" : 1,
	]));
	set("coor/x", 300);
	set("coor/y", -560);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

