// Room: /city/huadian.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�ݺӽ��ϳ����ĵ���֮һ�������������꣬���治��װ�μ��ӡ�
���������Ļ���ȴ�����򵥡�ͨ������������������Ҫ�ĸ��ֵ��ε�
������������Ȼ����ط��������ۣ�Զ���Ŀ��̶�Ը�������������
    ��������ϰ���Ц����ӭ��
LONG );
	set("objects", ([
		__DIR__"npc/yufan" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"caohecexiang",
	]));
	set("coor/x", -25);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}