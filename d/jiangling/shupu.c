//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG
���Ǿ��ݳ����һ�����̣�ƽʱ������Ϊ���壬���ȴ���˲��ٽ�
�����ͣ�������Ҫ����ʫѡ������������۵���������һ����Ҳ����
�ֺ����Ǯ��Ω������˾�û���ˡ�����Ļ����æ���к����ˣ�ü��
��Ц����Ǯ��Ǯ���������ϴ���������ͦ��͹�ǵ�����ʽү���ڴ�����
����������ʲô��ʱ��ͣ������������������飬�ƺ���������ʲô��
������ܡ�
LONG);
	set("exits", ([ 
		"east" : __DIR__"xijie3",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke"  : 2,
		"/d/taishan/npc/jian-ke": 1,
		"/d/taishan/npc/dao-ke" : 1,
	]));

	set("coor/x", -1510);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
