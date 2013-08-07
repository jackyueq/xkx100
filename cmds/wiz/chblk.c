// chblk.c

#include <globals.h>
inherit F_CLEAN_UP;

string *blocks_name = ({
	"all",
	"rumor",
	"chat",
	"xkx",
	"sing",
	"party",
	"family",
});
mapping ch_str = ([
	"all"	:	"����",
	"rumor"	:	"ҥ��",
	"chat"	:	"����",
	"xkx"	:	"������",
	"sing"	:	"�質",
	"party"	:	"���",
	"family":	"����",
]);

int main(object me, string arg)
{
	object ob;
	int i;
	string who, ch_name, str;
	
	if (!arg)
	{
		tell_object(me,"Ŀǰ���й���Ƶ����������£�\n");
		for (i = 1;i < sizeof(blocks_name);i ++)
		{
			str = "  ";
			str += ch_str[blocks_name[i]];
			str += "Ƶ����  ";
			if (CHANNEL_D->query_block("all")) str += "�ر�";
			else str += CHANNEL_D->query_block(blocks_name[i])?"�ر�":"��";
			str += "\n";
			tell_object(me,str);
		}	
		return 1;
	}

	if (sscanf(arg, "%s %s", who, ch_name) != 2)
	{
		ch_name = "";
		if (sscanf(arg, "%s", who) != 1)
		{
			return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
		}
	}
	//�ر�������ҵ�Ƶ��
	ob = LOGIN_D->find_body(who);
	if (ch_name == "")
	{
		if ( !ob && (member_array(who, blocks_name) == -1))
			return notify_fail("���޷��رմ�Ƶ������˲����ߣ�\n");
		else if ( !LOGIN_D->find_body(who)) {
			CHANNEL_D->set_block(who, 1);
			CHANNEL_D->do_channel(me, "sys", ch_str[who] + "Ƶ���ر��ˡ�\n");
			return 1;
		}		
	}
	if (!ob) return notify_fail("���˲����ߣ�\n");
	if (wizardp(ob)) return notify_fail("���ܹر���ʦ��Ƶ����\n");

	//�������Ƶ�������򷵻ظ��������Ƶ�����
	if (ch_name == "" || ch_name == " ") 
	{	
		for (i = 1;i <sizeof(blocks_name);i ++) 
			if ( ob->query("chblk_on") ||
				ob->query("chblk_" + blocks_name[i]) )
				tell_object(me, (string)ob->query("name") + "��" + ch_str[blocks_name[i]] + "Ƶ���ǹرյġ�\n");
		if (!(ob->query("chblk_on") ||
			ob->query("chblk_rumor") ||
			ob->query("chblk_chat") ||
			ob->query("chblk_xkx") ||
			ob->query("chblk_sing") ||
			ob->query("chblk_family") ||
			ob->query("chblk_party"))) 
		{
			tell_object(me,(string)ob->query("name")+"û�б��رյ�Ƶ����\n");
		} 
	}
	else
		if ( member_array(ch_name, blocks_name) != -1)
		{
			if (ch_name == "all")
			{
				if ( ob->query("chblk_on"))
					tell_object(me, (string)ob->query("name") + "������Ƶ���Ѿ��ǹرյġ�\n");
				else
				{
					ob->set("chblk_on",1);
					tell_object(me, (string)ob->query("name") + "������Ƶ�����ر��ˡ�\n");
				}	
			}
			else
				if ( ob->query("chblk_" + ch_name) )
				{
					 tell_object(me, (string)ob->query("name")+"��" + ch_str[ch_name] + "Ƶ���Ѿ��ǹرյġ�\n");
				}
				else
				{
					ob->set("chblk_" + ch_name, 1);
					tell_object(me, (string)ob->query("name")+"��" + ch_str[ch_name] + "Ƶ�����ر��ˡ�\n");
				}
		}
		else 
		{
			return notify_fail("<Syntax>: chblk <player id> <channel name>\n");
		}
		
	return 1;
}

int help(object me)
{
write(@HELP
    ָ���ʽ : chblk <ĳ��> <Ƶ����>

    ������ر�ĳ�˵�ĳ��Ƶ����

    ��������κβ���������ʾĿǰ����Ƶ���������
    <Ƶ����>��������rumor��chat��xkx��sing��party��family��all��
    ������ṩƵ����������ʾĳ�˵�ǰ��Ƶ��״̬�� 

���ң�
chblk rumor  ���ر�������ҵ�ҥ��Ƶ����
chblk chat   ���ر�������ҵ�����Ƶ����
chblk xkx    ���ر�������ҵ�������Ƶ����
chblk sing   ���ر�������Ҹ質Ƶ����
chblk party  ���ر�������ҵİ��Ƶ����
chblk family ���ر�������ҵ�����Ƶ����
chblk all    ���ر�������ҵ�����Ƶ����

HELP
    );
    return 1;
}

