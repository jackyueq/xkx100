// Room: /city/heyuanhouyuan.c

inherit ROOM;

void create()
{
	set("short", "��԰��Ժ");
	set("long", @LONG
�����������������װ��ø����ûʣ��������ɣ������¹���˿ȸ
��ü��������ת���������������ɺ���ͷ���Ժ�У�����ɢ����һЩ��
�Σ��Թ���Ժ����Ϣ��
LONG );
	set("exits", ([
		"north" : __DIR__"heyuan",
	]));
        set("objects", ([
		__DIR__"npc/he": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -52);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}