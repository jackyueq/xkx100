// /d/city/dahuashaizi.c

#include <ansi.h>;
inherit  ROOM;
string look_ban();

void create ()
{
	set ("short", "��������");
	set ("long", @LONG
�����Ǵ������ݣ������м����һ����̨����̨���ϣ��ò���
���š���ţ��Ҫ��Ǯ����������̨����������Ͳ����Ͳ������������
�ӣ��ƺ�����֮�󣬾��ɡ��󻰡�һ����ǽ�϶���һ��Сľ�� (ban)��
�����������д�˻����淨��
LONG);

	set("no_fight",  1);
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/dahuashaizi" : 1,
	]));
	set("item_desc", ([ 
		"ban": (: look_ban :),
	]));
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"shaiziting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 19);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}
string look_ban()
{
        return
"			������

����[��ʼ��Ϸ]����������
������Ϸ��join	��ʼ��Ϸ��start	������Ϸ��reset se
����[��Ϸ����]����������
ҡ���ӣ�toss	�鿴���ӣ�view [���ID]
׼��������finish/deal
�𴩴󻰣�dahua [���ID]
�²����ӣ�guess �������� ���ӵ���
�������������� g �������� ���ӵ���
�ߴ���ң�next
����[��������]����������
��������showc	�²���־��history
����[�Թ�����]����������
��ս���visit [-d] ���ID
                ����������ҹۿ������Ϸ��
                �Ӳ��� -d ��ʾɾ������ҵĹۿ��ʸ�
����[��Ϸ����]����������
    �����Ϸ�������Ϲ��ưɡ������ģ���Ӧ�����������˵����
�ܿ����ǻ۵ġ�\n";
}
