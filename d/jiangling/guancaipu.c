//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "�ײ���");
	set ("long", @LONG
����һ�����ײĵĵ��̣����治��ȴ�и���Ժ�����ڷ����õĹ�
�ġ��ƹ��վ���ſڣ���Ц��Ц�ض��������Ŀ��ˡ��������ҵ���ͷ��
�����˵����⻹ͦ��¡��һ�ƹ���͸����̨���С�ţ�����һ�������
�Ĺײİ��ϣ�����������Щ���ۡ�
LONG);
	set("exits", ([ 
		"east" : __DIR__"xijie2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
