// Room: /d/fuzhou/langguanxiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "�ɹ���");
	set("long", @LONG
�����������ڴˣ�����������Ϊ�ɹ٣������ɹ���δ���ʫ�˳�
�ң���������ϸ��Ĺʾ�Ҳ�������ڡ��ɹ���������Ʒ����������и�
�������������Իͣ������̴��ϸ�լ����ͥ��ʢ������Զ�����ξӡ���
LONG );

	set("exits", ([
		"west"    : __DIR__"nanhoujie2",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
