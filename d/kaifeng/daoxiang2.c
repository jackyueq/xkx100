// /kaifeng/daoxiang2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "����Ӷ�¥");
	set("long", @LONG
�ϴ�һ���������໥�����������ʮ���С�䡣����������С����
�Ų��������ߣ������������Ļ����������̵������ߵ�λ�á��ߺȾ�
�߿�������ķ����־�������һ�֡�
LONG);
	set("objects", ([
		__DIR__"npc/gaoyanei" : 1,
		__DIR__"npc/luyuhou" : 1,
	]));
	set("exits", ([
		"down" : __DIR__"daoxiang1",
	]));

	setup();
	replace_program(ROOM);
}
