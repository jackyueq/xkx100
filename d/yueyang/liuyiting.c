// Room: /d/yueyang/liuyijing.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "���㴫��ͤ");
	set("long", @LONG
���㴫��󣬶�ͥ����Ϊ�˱����������Ů֮����Ҫ���������޸�
���㣬������Ϊ������Σ��֮������֮���ݣ�������˶�Ϊı��������
л���ˡ������������Ľ�������Ů�����ҹ���������ɷ��ޣ�
���ŵ���ʵ�飬�����㷵�ض�ͥˮ�������㱻����Ϊ��ͥ����
    ����Ϊ�˼������㴫�飬�Ľ۾�Ϊ���㾮�����ھ��Խ������㴫��
ͤ(ting)��
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("item_desc", ([
		"ting" : "
      �������������Ϊ�д��������Σ�
      ����ֱ��Ѱ������Ī��ң����ͥ����
 �� ���������Ӽ귽���������ʾ����Ѷࡣ
  �������þ�ʱ�����ڣ���Ȫ������������\n"
	]));
	set("exits", ([
		"west" : __DIR__"liuyijing",
	]));
	set("coor/x", -1680);
	set("coor/y", 2310);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
