// unchblk.c

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
	string who, ch_name;
	
	if (!arg)
		return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
	if (sscanf(arg, "%s %s", who, ch_name) != 2)
	{
		ch_name = "";
		if (sscanf(arg, "%s", who) != 1)
		{
			return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
		}
	}
// ��������ҵ�Ƶ�� 	
    	ob = LOGIN_D->find_body(who);
	if (ch_name == "" && !ob && (member_array(who, blocks_name) == -1))
		return notify_fail("���޷��򿪴�Ƶ������˲����ߣ�\n");
//	if (!ob) return notify_fail("���˲����ߣ�\n");
	if (who == "all")
	{
		for (i = 0;i < sizeof(blocks_name);i ++)
			CHANNEL_D->set_block(blocks_name[i],0);
		CHANNEL_D->do_channel(me,"sys","����Ƶ��	�������\n");
		return 1;
	}	
    	for (i = 1;i < sizeof(blocks_name);i ++)
	{
		if (who	== blocks_name[i])
		{
			CHANNEL_D->set_block(who, 0);
			CHANNEL_D->do_channel(me, "sys", ch_str[who] + "Ƶ���������\n");
			return 1;
		}
	}			
	if (ch_name == ""||ch_name == " "||ch_name == "all")
	{	
		if ((int)ob->query("chblk_on") ||
			(int)ob->query("chblk_rumor") ||
			(int)ob->query("chblk_chat") ||
			(int)ob->query("chblk_xkx") ||
			(int)ob->query("chblk_sing") ||
			(int)ob->query("chblk_family") ||
			(int)ob->query("chblk_party"))
                {
			ob->delete("chblk_on");
			for (i = 1;i < sizeof(blocks_name);i ++)
				ob->delete("chblk_" + blocks_name[i]);
			tell_object(me,(string)ob->query("name") + "������Ƶ�������ˡ�\n");
		}
		else tell_object(me, (string)ob->query("name") + "������Ƶ���������ǿ��ŵġ�\n");	
	}
	else
		if (member_array(ch_name, blocks_name, 1) != -1)
		{
			if ((int)ob->query("chblk_" + ch_name))
			{
				ob->delete("chblk_on");
				ob->delete("chblk_" + ch_name);
				tell_object(me, (string)ob->query("name") + "��" + ch_str[ch_name] + "Ƶ�������ˡ�\n");
			}
			else tell_object(me, (string)ob->query("name") + "��" + ch_str[ch_name] + "Ƶ���������ǿ��ŵġ�\n");	
		}
		else 
		{
			return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
		}
	return 1;
}

int help(object me)
{
write(@HELP
    ָ���ʽ : unchblk <ĳ��> <Ƶ����>

    �������ĳ�˵�Ƶ�������û��Ƶ�����ʹ����кϷ�Ƶ����
    <ĳ��>��Ҳ������Ƶ�������⽫��������ҵ�ĳ��Ƶ����
    <Ƶ����> ������rumor�� chat�� xkx�� sing�� party��family����all

HELP
    );
    return 1;
}

