// /kaifeng/jiedao1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set ("short", "Ұ����");
	set ("long", @LONG
�ԴӲ���ǰ�������г���Ұ��֮����Ƭ���־����������⾳�ڣ�
̸��ɫ�ߡ�ֻ��Ϊ�������ȵ����ӻ����ֱߴ�ЩҰ���������ո�ǿ��
ͼ��·����Ҳ�Ӵ˹��������˵ر��ǻ�ɽ��
LONG);

	set("outdoors", "kaifeng");
	set("exits", ([
		"northeast" : __DIR__"dadao2",
	]));
	set("objects", ([
		ANIMAL_DIR"pig" : random(2)+1,
	]));
	setup();
	replace_program(ROOM);
}
